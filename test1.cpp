Anurag has two strings s and sub. He likes playing around with substrings and as a pastime he always plays around with various combinations of characters of strings s and sub in order to make one,the substring of the other if possible.

He had a very dear friend from his college who always assisted him in every task. She (named Georgia) used to help Anurag, in his liking of checking and playing around with substrings, by maintaining a 2D character array mapping. Due to some unfortunate turn of situations and circumstances, she stopped helping out Anurag with his will of playing around with substrings.

Now Anurag is left alone with the heavy task of checking if it is possible to make the sub a substring of s by replacing characters according to the provided mappings left by his dear friend. Each mapping was described to consist of a pair [oi, ni] . Georgia had described that it was only possible to replace the character oi in sub with character ni.

It was also informed to Anurag by her that the replacement could be performed as per the following rule:

Choose any character from sub (o[i]) and replace it with the mapping (n[i]), where o[i] and n[i] belongs to the mapping.

He can perform the above operation any number of times as he wishes but only once for each character in sub. Meaning for a sub of length k , he can replace 0 to k characters from the mapping.

Months later of no talking between the two friends, Georgia texted asking Anurag whether he was able to create sub as a substring of s using the given replacements (as allowed in the mappings given by her). Return YES if possible else return NO.

Input Format

The first line contains the string s.
Second line contains the string sub.
Third line contains n (lenght of the mappings).
Next n lines contains o[i] and n[i] (space separated).
Constraints

1 <= sub.length <= s.length <= 500000
0 <= n(mappings.length) <= 10000
mappings[i].length == 2
o[i] != n[i]
Expected Time Limit- 1second
Solutions will be run on some hidden system test cases after the contest ends. Make sure the solution is the most optimal one considering the above constraints to pass all the hidden test cases as well within the time limit of 1 second.
Output Format

Print YES if sub can be a substring of s else print NO.

Sample Input 0

fooig3zakwew
ggab
3
a 3
g i
b z
Sample Output 0

YES
Explanation 0

We replace the first occurance of 'a' with 3 and first occurance of g with i and first occurance of b with z which makes sub=ig3z. Which is a substring of s .

Sample Input 1

Fool33tbaR
leetd
5
e 3
t 7
t 8
d b
p b
Sample Output 1

YES
Explanation 1

We replace the first and second occurrences of 'e' in sub with '3' and 'd' in sub with 'b', respectively. This transforms sub into 'l33tb', which is a substring of s. Therefore, we return YES.