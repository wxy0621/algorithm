// 交替打印字符串
#include <semaphore.h>

class FizzBuzz {
private:
    int n;
    int cur;
    sem_t sem_fizz;
    sem_t sem_buzz;
    sem_t sem_fizzbuzz;
    sem_t sem_num;
public:
    FizzBuzz(int n) {
        this->n = n;
        cur = 0;
        sem_init(&sem_fizz, 0, 0);
        sem_init(&sem_buzz, 0, 0);
        sem_init(&sem_fizzbuzz, 0, 0);
        sem_init(&sem_num, 0, 1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (cur <= n) {
            sem_wait(&sem_fizz);
            if (cur > n) break;
            printFizz();
            sem_post(&sem_num);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (cur <= n) {
            sem_wait(&sem_buzz);
            if (cur > n) break;
            printBuzz();
            sem_post(&sem_num);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (cur <= n) {
            sem_wait(&sem_fizzbuzz);
            if (cur > n) break;
            printFizzBuzz();
            sem_post(&sem_num);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (++cur <= n) {
            sem_wait(&sem_num);
            if (cur % 3 == 0 && cur % 15 != 0) {
                sem_post(&sem_fizz);
            } else if (cur % 5 == 0 && cur % 15 != 0) {
                sem_post(&sem_buzz);
            } else if (cur % 3 == 0 && cur % 5 == 0) {
                sem_post(&sem_fizzbuzz);
            } else {
                printNumber(cur);
                sem_post(&sem_num);
            }
        }
        sem_post(&sem_fizz);
        sem_post(&sem_buzz);
        sem_post(&sem_fizzbuzz);
    }
};