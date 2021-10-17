def play_the_game(target) :
    buckets = [0] * len(target)
    count = 0

    while(True):

        started = 0
        adder = 0
        doubled = 0
        for j in range(0, len(target)) :
            if (buckets[j] != target[j]) :
                if (buckets[j] == 0) :
                    buckets[j] += 1
                    started += 1
                elif ((buckets[j] * 2) >= (buckets[j] + 1) and (buckets[j] * 2) <= target[j]) :
                    buckets[j] *= 2
                    doubled += 1
                elif ((buckets[j] + 1) <= target[j]) :
                    buckets[j] += 1
                    adder += 1

        if (started == 0 and doubled == 0 and adder == 0) : break

        if (doubled == len(target)) : count += 1
        else : count += (started + doubled + adder)

    return count


if __name__ == "__main__":
    target = list(map(int, input().split()))
    count = play_the_game(target)
    print(count)