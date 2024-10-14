import csv
from datetime import datetime, timedelta
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ").title()
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):

    # ---------------    START TEST    ---    DEBUG

    # new_cases = {
    # 'Alabama': {
    #     '2023-03-23': 100,
    #     '2023-03-22': 90,
    #     '2023-03-21': 80,
    #     '2023-03-20': 70,
    #     '2023-03-19': 60,
    #     '2023-03-18': 50,
    #     '2023-03-17': 40,
    #     '2023-03-16': 30,
    #     '2023-03-15': 20,
    #     '2023-03-14': 10,
    #     '2023-03-13': 5,
    #     '2023-03-12': 3,
    #     '2023-03-11': 2,
    #     '2023-03-10': 1
    #     }
    # }

    # ---------------    END TEST    ---    DEBUG

    # Create the list, start from most recent day
    sorted_data = sorted(reader, key=lambda row: row['date'], reverse=True)

    # Create a list to sort
    all_cases = []

    # Set countdown
    days_countdown = 0

    # Recent 14 days
    two_weeks = 14

    # 56 states in the list
    amount_of_states = 56

    # Fill the list with cases for 14 days
    # Example: {'date': '2023-03-23', 'state': 'Alabama', 'fips': '01', 'cases': '1648385', 'deaths': '21631'}
    for row in sorted_data:

        # Append row to list
        all_cases.append(row)

        # Check for the last state
        if int(row['fips']) == amount_of_states:
            days_countdown += 1

        # Check for 14 days
        if days_countdown == two_weeks + 1:
            break

    # for row in cases:   # DEBUG
    #     print(row)

    # Create a dictionary for 14-days cases
    new_cases = {}
    for row in all_cases:

        # Assign index for list
        state = row['state']

        # Make the list with new states
        if state not in new_cases:
            new_cases[state] = {}

        # Fill the dictionary: key - date, value - cases
        new_cases[state][row['date']] = int(row['cases'])

    # for key, value in new_cases.items():    # DEBUG
    #     print(key, value)

    # Fill dictionary with results

    for state in new_cases:

        count = 0

        # Iterate through keys with dates
        for date in new_cases[state]:

            # Set current date
            current_day_obj = datetime.strptime(date, '%Y-%m-%d')

            # Set previous date
            previous_day_obj = current_day_obj - timedelta(days=1)
            previous_day_str = previous_day_obj.strftime('%Y-%m-%d')

            if count == two_weeks:
                del new_cases[state][date]
                break

            # Calculate cases
            if previous_day_str in new_cases[state]:

                current_day = int(new_cases[state][date])
                prev_day = int(new_cases[state][previous_day_str])

                result = current_day - prev_day
                new_cases[state][date] = result
                count += 1

    # for key, value in new_cases.items():    # DEBUG
    #     print(key, value)

    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):

    # for key, value in new_cases.items():    # DEBUG
    #     print(key, value)

    # print(states)    # DEBUG

    current_week_sum = 0
    prev_week_sum = 0
    current_week_days = 0
    prev_week_days = 0

    # Iterate through each state
    for state in states:

        # Reset sum and days
        current_week_sum = 0
        prev_week_sum = 0
        current_week_days = 0
        prev_week_days = 0

        # Iterate each date
        for date in new_cases[state]:
            # Calculate the last week
            if current_week_days < 7:
                current_week_sum += int(new_cases[state][date])
                current_week_days += 1
            # Calculate the previous week
            else:
                prev_week_sum += int(new_cases[state][date])
                prev_week_days += 1

        # Calculate averages
        current_week_avg = current_week_sum / current_week_days
        prev_week_avg = prev_week_sum / prev_week_days

        # Calculate difference of averages between current and previous week in %
        comparison = (current_week_avg - prev_week_avg) / \
                     ((current_week_avg + prev_week_avg) / 2) * 100

        # --- Print results
        # Increase
        if comparison > 0:
            print(
                f"{state} had a 7-day average of {round(current_week_avg)} and an increase of {round(comparison)}%.")
        # Decrease
        elif comparison < 0:
            print(
                f"{state} had a 7-day average of {round(current_week_avg)} and a decrease of {round(comparison)}%.")
        # Equal
        else:
            print(f"{state} had a 7-day average of {round(current_week_avg)}, the same as on the last week.")


main()
