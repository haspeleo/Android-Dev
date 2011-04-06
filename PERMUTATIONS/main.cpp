/*
 * http://www.codeguru.com/cpp/cpp/algorithms/article.php/c5123 --permutation
 * http://stattrek.com/Tools/EventCounter.aspx -- probabilities
 * http://www.mathsisfun.com/combinatorics/combinations-permutations.html --fun math
 */

#include <string>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T, typename Func>
void vector_permutation(std::vector<T>& now, std::vector<T> next, Func func) {
    int size = now.size();
    if (size > 0) {
        for (int cnt = 0; cnt < size; ++cnt) {
            std::vector<T> vt;

            //std::vector<T>::const_iterator it;
            typename  std::vector<T>::const_iterator it;
            it = now.begin();
            for (int cnt1 = 0; cnt1 < size; ++cnt1) {
                if (cnt1 == cnt) {
                    ++it;
                    continue;
                } else
                    vt.push_back(*it);
                ++it;
            }

            typename std::vector<T>::const_iterator it1;
            it1 = now.begin();
            --it1;
            for (int cnt2 = 0; cnt2 <= cnt; ++cnt2) {
                ++it1;
            }

            next.push_back(*it1);
            vector_permutation(vt, next, func);
            next.pop_back();
        }

    }
    else {
        func(next);
    }
}

//using iterators

//void display(vector<char> perm) {
//    for (vector<char>::iterator it = perm.begin(); it != perm.end(); ++it)
//        cout << *it;
//    cout << endl;
//}
template <typename T>
void display(vector<T> perm) {
    for (typename vector<T>::iterator it = perm.begin(); it != perm.end(); ++it)
        cout << *it;
    cout << endl;
}

void string_permutation(std::string& orig, std::string& perm) {
    if (orig.empty()) {
        std::cout << perm << std::endl;
        return;
    }

    for (int i = 0; i < orig.size(); ++i) {
        std::string orig2 = orig;
        orig2.erase(i, 1);
        std::string perm2 = perm;
        perm2 += orig.at(i);
        string_permutation(orig2, perm2);
    }
}

int main() {
    std::string orig = "ABCDE";
    std::string perm;

    cout << "Permutations " << endl;
    string_permutation(orig, perm);

    
    cout << "Template Permutations" << endl;

    vector<string> v;
    vector<string> w;

    v.push_back("A");
    v.push_back("B");
    v.push_back("C");
    v.push_back("D");
    v.push_back("E");
    v.push_back("E");
    v.push_back("F");
    v.push_back("G");
    v.push_back("H");
    v.push_back("I");
    v.push_back("J");

    vector_permutation(v, w, display<string>);


    return 0;
}




