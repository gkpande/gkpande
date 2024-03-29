<h2><a href="https://practice.geeksforgeeks.org/problems/game-with-string4100/1?page=1&status[]=unsolved&company[]=Amazon&sprint=94ade6723438d94ecf0c00c3937dad55&sortBy=submissions">Game with String</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string <strong>s</strong> of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of <strong>k</strong> characters. The value of a string is defined as the sum of squares of the count of each distinct character.</span><br>
&nbsp;</p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> s = abccc, k = 1
<strong>Output:</strong> 6
<strong>Explaination:
</strong>We remove c to get the value as 1<sup>2</sup></span><span style="font-size:18px"> + 1<sup>2</sup></span><span style="font-size:18px"> + 2<sup>2</sup></span>
</pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input: </strong>s = aabcbcbcabcc, k = 3
<strong>Output:</strong> 27
<strong>Explaination:</strong> We remove two 'c' and one 'b'. 
Now we get the value as 3<sup>2 </sup>+ 3<sup>2</sup> + 3<sup>2</sup>.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>minValue()</strong> which takes s and k as input parameters and returns the minimum possible required value.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N+Klog(P))&nbsp; where N is the length of string and P&nbsp;is number of distinct alphabets and K&nbsp;number of alphabets to be removed&nbsp;<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ k ≤ |string length| ≤ 100</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Heap</code>&nbsp;<code>Data Structures</code>&nbsp;