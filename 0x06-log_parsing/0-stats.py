#!/usr/bin/python3
"""script that reads stdin line by line and computes metrics"""

if __name__ == "__main__":
    import sys

    count = 0
    fileSize = 0
    statCount = {"200": 0, "301": 0, "400": 0, "401": 0,
                 "403": 0, "404": 0, "405": 0, "500": 0}

    try:
        for line in sys.stdin:
            count += 1
            split = line.split(" ")
            try:
                status = split[-2]
                fileSize += int(split[-1])
                if status in statCount:
                    statCount[status] += 1
            except Exception:
                pass

            if count % 10 == 0:
                print("File size: {}".format(fileSize))
                for key in sorted(statCount.keys()):
                    if statCount[key] == 0:
                        continue
                    print("{}: {}".format(key, statCount[key]))

        else:
            print("File size: {}".format(fileSize))
            for key in sorted(statCount.keys()):
                if statCount[key] == 0:
                    continue
                print("{}: {}".format(key, statCount[key]))

    except (KeyboardInterrupt, SystemExit):
        print("File size: {}".format(fileSize))
        for key in sorted(statCount.keys()):
            if statCount[key] == 0:
                continue
            print("{}: {}".format(key, statCount[key]))
        raise
