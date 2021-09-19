/*
 * @Author: FANG
 * @Date: 2021-09-19 21:54:41
 * @LastEditTime: 2021-09-19 21:54:41
 * @Description: Fizz Buzz
 * @FilePath: \DSA\QuestionSet\Leetcode\C-Puls-Puls\412. Fizz Buzz.cpp
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) v.push_back("FizzBuzz");
            else if (i % 3 == 0) v.push_back("Fizz");
            else if (i % 5 == 0) v.push_back("Buzz");
            else v.push_back(to_string(i)); 
        }
        return v;
    }
};