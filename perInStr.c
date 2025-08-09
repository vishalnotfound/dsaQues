/*
#steps involed + explainantion;

if s1.size() is bigger than s2.size, return false

create s1Counter & s2Counter of 26 lenth each intilized with 0 and each to hold the frequiency in this array for each element in s1 and s2 (which could be like this if s1[ ] = {a(1st number of alphabet ),c(3rd),d(4th)} so s1Count[26] = {freq of elmnt a = 1, 1, 1}

and s1Count would look like s1Count[26] = {1,0,1,1,0,0-------upto 26the elmt 0}

we'll use for loop to store the frequencies of
if s1 have one number many times so
  for (char c : s1) {
        s1Count[c - 'a']++;
    }
so loop go on and increment s1Count[targeted elmt] with 1

chech if the s1count and s2Count are equal
(if the frequncies at corresponding chars are equal)
if are, return true;

otherwise search next set of s1.lenth elmnts in s2
use for loop and intialize i with s1.size than mean it had checked already previous elmnts, i < s2.size; i++
        s2Count[s2[i] - 'a']++;                 // Add new char to window
        s2Count[s2[i - s1.size()] - 'a']--;     // Remove old char from window

compare every time in same loop if they are equaL
 // Compare counts
        if (s1Count == s2Count) return true;
        */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;

    vector<int> s1Count(26, 0), s2Count(26, 0);

    // Count frequency of each character in s1
    for (char c : s1)
    {
        s1Count[c - 'a']++;
    }

    // Initialize the first window
    for (int i = 0; i < s1.size(); i++)
    {
        s2Count[s2[i] - 'a']++;
    }

    // Check if the first window matches
    if (s1Count == s2Count)
        return true;

    // Slide the window across s2
    for (int i = s1.size(); i < s2.size(); i++)
    {
        s2Count[s2[i] - 'a']++;             // Add new char to window
        s2Count[s2[i - s1.size()] - 'a']--; // Remove old char from window

        // Compare counts
        if (s1Count == s2Count)
            return true;
    }

    return false;
}

int main()
{
    string s1 = "abc";
    string s2 = "eidbaooo";

    bool res = checkInclusion(s1, s2);
    if (res)
    {
        cout << "Item found" << endl;
    }
    else
    {
        cout << "Item not found" << endl;
    }
}
