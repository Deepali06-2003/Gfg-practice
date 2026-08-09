<h2><a href="https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1?page=2&category=Graph">Find shortest safe route in a matrix</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p data-start="0" data-end="220"><span style="font-size: 14pt;">You are given a 2D matrix <strong>mat[][]</strong> of size <strong>n</strong> × <strong>m</strong>, where each cell is either <strong>0</strong> (landmine) or <strong>1</strong> (safe).&nbsp;</span><span style="font-size: 18.6667px;">Find the <strong>minimum </strong>number of steps required to travel from any cell in the leftmost column to any cell in the rightmost column.</span></p>
<p data-start="0" data-end="220"><span style="font-size: 14pt;">You can move only in four directions: <strong>up</strong>, <strong>down</strong>, <strong>left</strong>, and <strong>right</strong>. A cell is unsafe if it contains a landmine or is directly adjacent (up, down, left, or right) to a landmine, and such cells must be avoided.</span></p>
<p data-start="0" data-end="220"><span style="font-size: 14pt;">Return the <strong>minimum </strong>number of steps required to reach the last column, or -1 if no safe path exists.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:</span> </strong><span style="font-size: 18px;">mat[][] = [[1, 0, 1, 1, 1],
               [1, 1, 1, 1, 1],
               [1, 1, 1, 1, 1],
               [1, 1, 1, 0, 1],
               [1, 1, 1, 1, 0]]</span>
<strong><span style="font-size: 18px;">Output: </span></strong><span style="font-size: 18px;">6</span>
<strong><span style="font-size: 18px;">Explanation: </span></strong>
<span style="font-size: 18px;">We can see that length of shortest</span> <span style="font-size: 18px;">safe route is 6.</span>
<span style="font-size: 14pt;">[1 0 1 1 1]<br>[1 1 <span style="color: #236fa1;"><strong>1</strong> <strong>1</strong> <strong>1</strong></span>]<span style="color: #236fa1;"><br></span>[<span style="color: #236fa1;"><strong>1</strong></span> <span style="color: #236fa1;"><strong>1</strong></span> <span style="color: #236fa1;"><strong>1</strong></span> 1 1]
[1 1 1 0 1] 
[1 1 1 1 0]
</span></pre>
<pre><strong><span style="font-size: 18px;">Input: </span></strong><span style="font-size: 18px;">mat[][] = [[1, 1, 1, 1, 1],
               [1, 1, 0, 1, 1],
               [1, 1, 1, 1, 1]]</span><strong><span style="font-size: 18px;">
Output: </span></strong><span style="font-size: 18px;">-1</span><strong><span style="font-size: 18px;">
Explanation: </span></strong><span style="font-size: 18px;">There is no possible path from first column to last column.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, m ≤ 10</span><sup><span style="font-size: 15px;">3</span></sup><span style="font-size: 15px;"><br><span style="font-size: 14pt;">0 ≤ mat[i][j] ≤ 1</span></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Graph</code>&nbsp;