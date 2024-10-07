# Global variable `words`
# `set()` - is a collection of things that won't contain duplicates.
# Duplicates will be filtered out automatically.
words = set()

# Define a function
def check(word):
    # Check that word is within the set of words
    return word.lower() in words

def load(dictionary):
    # Open dictionary as a variable `file`
    with open(dictionary) as file:
        # Update the set of words to be the updated version of smth from `file` as a result of reading.
        # Then splitting its lines into one big collection.
        words.update(file.read().splitlines())
    return True

def size():
    return len(words)

def unload():
    # There is no necessity to unload, Python manages your memory for you.
    return True