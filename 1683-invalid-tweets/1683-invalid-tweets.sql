# Write your MySQL query statement below


# LENGTH() returns the length of the string measured in bytes.
# CHAR_LENGTH() returns the length of the string measured in characters.
# This is especially relevant for Unicode, in which most characters are encoded in two bytes, or UTF-8, where the number of bytes varies.

# Example:

# SELECT LENGTH('€')  # is equal to 3
# SELECT CHAR_LENGTH('€') # is equal to 1


select tweet_id from Tweets where length(content) > 15;
