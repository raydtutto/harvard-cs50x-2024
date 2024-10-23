-- Keep a log of any SQL queries you execute as you solve the mystery.

/* Step 1. We need to find more data about the case.
 * Available information:
 * - Description: Theft of CS50 duck
 * - Street: Humphrey Street
 * - Year: 2023
 * - Month: 7
 * - Day: 28 */

SELECT *
FROM crime_scene_reports
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND street = 'Humphrey Street'
  AND description LIKE 'Theft%'  -- Find the type of a crime at the beggining of description.

    -- Result 1 --
    -- ID: 295
    --      Description: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
    --                   Interviews were conducted today with three witnesses who were present at the time –
    --                   each of their interview transcripts mentions the bakery. */


/* Step 2. Find the interviews of 3 witnesses.
 * Available information:
 * - ID: 295
 * - Time: 10:15am
 * - Place: Bakery
 * - Witnesses: 3 */

SELECT *
FROM interviews
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND transcript LIKE '%bakery%';  -- Find the scene of a crime in the transcript.

    -- Result 2 --
    -- ID: 161
    --      Name: Ruth
    --      Transcript: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking
    --                  lot and drive away. If you have security footage from the bakery parking lot, you might want
    --                  to look for cars that left the parking lot in that time frame.
    -- ID: 162
    --      Name: Eugene
    --      Transcript: I don't know the thief's name, but it was someone I recognized. Earlier this morning,
    --                  before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw
    --                  the thief there withdrawing some money.
    -- ID: 163
    --      Name: Raymond
    --      Transcript: As the thief was leaving the bakery, they called someone who talked to them for less than
    --                  a minute. In the call, I heard the thief say that they were planning to take the earliest
    --                  flight out of Fiftyville tomorrow. The thief then asked the person on the other end
    --                  of the phone to purchase the flight ticket. */


/* Step 3. Check Ruth's interview: security footage from the bakery parking lot.
 * Available information:
 * - Time: Within 10 minutes from the crime time
 * - Place: Bakery parking lot */

SELECT *
FROM bakery_security_logs
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND hour = 10
  AND minute >= 15
  AND minute <= 25;

    -- Result 3 --
    -- ID: 260  Minute: 16  Activity: exit  License_plate: 5P2BI95
    -- ID: 261  Minute: 18  Activity: exit  License_plate: 94KL13X
    -- ID: 262  Minute: 18  Activity: exit  License_plate: 6P58WS2
    -- ID: 263  Minute: 19  Activity: exit  License_plate: 4328GD8
    -- ID: 264  Minute: 20  Activity: exit  License_plate: G412CB7
    -- ID: 265  Minute: 21  Activity: exit  License_plate: L93JTIZ
    -- ID: 266  Minute: 23  Activity: exit  License_plate: 322W7JE
    -- ID: 267  Minute: 23  Activity: exit  License_plate: 0NTHK55


/* Step 4. Check Eugene's interview: money withdrawal from an ATM on Leggett Street.
 * Available information:
 * - Time: Before the crime time
 * - Place: ATM on Leggett Street
 * - Description: Thief was withdrawing some money */

SELECT *
FROM atm_transactions
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND atm_location = 'Leggett Street'
  AND transaction_type = 'withdraw';

    -- Result 4 --
    -- ID: 246  Account number: 28500762  Amount: 48
    -- ID: 264  Account number: 28296815  Amount: 20
    -- ID: 266  Account number: 76054385  Amount: 60
    -- ID: 267  Account number: 49610011  Amount: 50
    -- ID: 269  Account number: 16153065  Amount: 80
    -- ID: 288  Account number: 25506511  Amount: 20
    -- ID: 313  Account number: 81061156  Amount: 30
    -- ID: 336  Account number: 26013199  Amount: 35


/* Step 5. Check Raymond's interview: check the phone calls.
 * Available information:
 * - Time: After the crime time
 * - Place: Bakery on Humphrey Street
 * - Description: Thief called someone and have a talk for less than a minute. */

SELECT *
FROM phone_calls
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND duration < 60;

    -- Result 5 --
    -- ID: 221  Caller: (130) 555-0289  Receiver: (996) 555-8899  Duration: 51
    -- ID: 224  Caller: (499) 555-9472  Receiver: (892) 555-8872  Duration: 36
    -- ID: 233  Caller: (367) 555-5533  Receiver: (375) 555-8161  Duration: 45
    -- ID: 251  Caller: (499) 555-9472  Receiver: (717) 555-1342  Duration: 50
    -- ID: 254  Caller: (286) 555-6063  Receiver: (676) 555-6554  Duration: 43
    -- ID: 255  Caller: (770) 555-1861  Receiver: (725) 555-3243  Duration: 49
    -- ID: 261  Caller: (031) 555-6622  Receiver: (910) 555-3251  Duration: 38
    -- ID: 279  Caller: (826) 555-1652  Receiver: (066) 555-9701  Duration: 55
    -- ID: 281  Caller: (338) 555-6650  Receiver: (704) 555-2131  Duration: 54


/* Step 6. Check Raymond's interview: find Fiftyville's airport id. */

SELECT *
FROM airports
WHERE city = 'Fiftyville';

    -- Result 6 --
    -- ID: 8  Abbreviation: CSF  Full name: Fiftyville Regional Airport


/* Step 7. Check Raymond's interview: check the flights from Fiftyville.
 * Available information:
 * - Time: Morning
 * - Date: 2023-7-29
 * - Description: Find the earliest flight out of Fiftyville.
                  The person on the other end of the phone had to purchase the flight ticket. */

SELECT *
FROM flights
WHERE year = 2023
  AND month = 7
  AND day = 29
  AND origin_airport_id = 8
  AND hour < 12;

    -- Result 7 --
    -- The earliest flight:
    --      ID: 36  Origin: 8 Destination: 4  Hour: 8  Minute: 20


/* Step 8. Check the flight destination. */

SELECT *
FROM airports
WHERE id = 4;

    -- Result 8 --
    -- Abbreviation: LGA  Full name: LaGuardia Airport  City: New York City


/* Step 9. Check the passengers.
 * Available information:
 * - ID: 36 */

SELECT *
FROM passengers
WHERE flight_id = 36;

    -- Result 9 --
    -- Passport: 7214083635  Seat: 2A
    -- Passport: 1695452385  Seat: 3B
    -- Passport: 5773159633  Seat: 4A
    -- Passport: 1540955065  Seat: 5C
    -- Passport: 8294398571  Seat: 6C
    -- Passport: 1988161715  Seat: 6D
    -- Passport: 9878712108  Seat: 7A
    -- Passport: 8496433585  Seat: 7B


/* Step 10. Combine available info from passengers, phone_calls, bakery_security_logs and atm_transactions
 *          with people. */

SELECT *
FROM people
WHERE people.passport_number IN (
    '7214083635',
    '1695452385',
    '5773159633',
    '1540955065',
    '8294398571',
    '1988161715',
    '9878712108',
    '8496433585'
)
AND people.phone_number IN (
    '(130) 555-0289',
    '(499) 555-9472',
    '(367) 555-5533',
    '(499) 555-9472',
    '(286) 555-6063',
    '(770) 555-1861',
    '(031) 555-6622',
    '(826) 555-1652',
    '(338) 555-6650'
)
AND people.license_plate IN (
    '5P2BI95',
    '94KL13X',
    '6P58WS2',
    '4328GD8',
    'G412CB7',
    'L93JTIZ',
    '322W7JE',
    '0NTHK55'
)
AND people.id IN (
    SELECT bank_accounts.person_id
    FROM bank_accounts
    WHERE bank_accounts.account_number IN (
        '28500762',
        '28296815',
        '76054385',
        '49610011',
        '16153065',
        '25506511',
        '81061156',
        '26013199'
    )
);

    -- Result 10 --
    -- ID: 686048
    -- Name: Bruce
    -- Phone number: (367) 555-5533
    -- Passport number: 5773159633
    -- License plate: 94KL13X


/* Step 11. Find the phone number of an accomplice. */

SELECT *
FROM phone_calls
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND duration < 60
  AND caller = '(367) 555-5533';

    -- Result 11 --
    -- Receiver: (375) 555-8161


/* Step 12. Find the data about an accomplice. */

SELECT *
FROM people
WHERE phone_number = '(375) 555-8161';

    -- Result 12 --
    -- ID: 864400
    -- Name: Robin
    -- Passport number: NULL
    -- License plate: 4V16VO0