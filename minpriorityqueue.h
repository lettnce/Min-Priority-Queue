#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include <unordered_map>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

template <typename T>
class MinPriorityQueue {
    public:

        MinPriorityQueue() {
        }

        int parent(int index)
        {
            return (index - 1) / 2;
        }

        int left_child(int index)
        {
            return (2 * index) + 1;
        }

        int right_child(int index) 
        {
            return (2 * index) + 2;
        }

        void push(T key, int val) {
            // insert element in structure
            pair<T, int> pair_input = {key, val};
            H.push_back(pair_input);

            if (H.size() == 1) { return; }

            int i = H.size() - 1;

            // while parent is greater than child, bubble up
            while (H[parent(i)].second > H[i].second) {
                swap(H[i], H[parent(i)]);
                i = parent(i);
            }
        }

        void pop() {
            // if vec = {}
            if (H.size() == 0) {
                return;
            }

            // if vec = {x}
            if (H.size() == 1) {
                H.pop_back();
                return;
            }

            swap(H[0], H[H.size() - 1]);
            H.pop_back();

            int i = 0;

            while (right_child(i) < H.size() - 1 && H[parent(i)].second > H[left_child(i)].second || H[parent(i)].second > H[right_child(i)].second) {
                if (H[left_child(i)].second < H[right_child(i)].second) {
                    swap(H[parent(i)], H[left_child(i)]);
                    i = left_child(i);
                }
                else {
                    swap(H[parent(i)], H[right_child(i)]);
                    i = right_child(i);
                }
                if (i >= H.size() / 2) { break; }
            }
            if (left_child(i) < H.size() - 1 && H[left_child(i)].second < H[parent(i)].second) {
                swap(H[parent(i)], H[left_child(i)]);
            }
            
        }
        T front() {
            return H[0].first;
        }

        int size() {
            return H.size();
        }

    private:
        vector< pair<T, int> > H;
        unordered_map<T, int> I;
};

#endif