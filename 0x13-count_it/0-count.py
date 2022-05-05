#!/usr/bin/python3
"""Queries Reddits API and print matched elements and their quantity"""
from requests import get


def count_words(subreddit, word_list, word_dict={}, after=""):
    """prints each matched word and quantity found"""
    if len(word_dict) <= 0:
        for word in word_list:
            word_dict[word] = 0

    if after is None:
        word_list = [[key, value] for key, value in word_dict.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for i in word_list:
            if i[1]:
                print("{}: {}".format(i[0].lower(), i[1]))
        return None

    res = get(
        "https://api.reddit.com/r/{}/hot".format(subreddit),
        headers={'user-agent': 'my-app/0.0.1'},
        params={'limit': 100, 'after': after},
        allow_redirects=False,
    )

    if res.status_code == 200:
        after = res.json().get('data').get('after')
        children = res.json().get('data').get('children')
        for child in children:
            title = child.get('data').get('title')
            lower = [j.lower() for j in title.split(' ')]
            for word in word_list:
                word_dict[word] += lower.count(word.lower())
    else:
        return None

    count_words(subreddit, word_list, word_dict, after)
