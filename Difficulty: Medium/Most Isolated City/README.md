<h2><a href="https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1">Most Isolated City</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">There are <strong>n</strong> cities labeled from 0 to n - 1 and <strong>m</strong> bidirectional weighted edges connecting them. Given a 2D array <strong>edges[][]</strong>, where each edges[i] = [from<sub>i</sub>, to<sub>i,</sub> weight<sub>i]</sub> represents a bidirectional edge between cities<strong> </strong>from<sub>i</sub>&nbsp;and to<sub>i</sub>&nbsp;with weight weight<sub>i</sub>.</span></p>
<p><span style="font-size: 18px;">Also given an integer <strong>dis</strong>. For each city, consider all other cities that are reachable through some path with a shortest path distance of at most dis. Return the city that can reach the fewest such cities. If multiple cities satisfy this condition, return the city with the greatest label.</span></p>
<p><strong><span style="font-size: 18px;">Examples</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:</span> </strong><span style="font-size: 18px;">n = 4, m = 4, dis = 4, </span><span style="font-size: 18px;">edges = [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]]</span>
<strong><span style="font-size: 18px;">Output: </span></strong><span style="font-size: 18px;">3</span>
<strong><span style="font-size: 18px;">Explanation:<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/711146/Web/Other/blobid1_1745300064.jpg" width="278" height="278"><br></span></strong><span style="font-size: 18px;">The neighboring cities at a distance of dis for each city are:
City 0 -&gt; [City 1, City 2]&nbsp;
City 1 -&gt; [City 0, City 2, City 3]&nbsp;
City 2 -&gt; [City 0, City 1, City 3]&nbsp;
City 3 -&gt; [City 1, City 2]&nbsp;
Cities 0 and 3 have 2 neighboring cities at a dis = 4, but we have to return city 3 since it has the greatest label.</span>
</pre>
<pre><strong><span style="font-size: 18px;">Input:&nbsp;</span></strong><span style="font-size: 18px;"><span style="font-size: 18px;">n = 5, m = 6, dis = 2, edges = [[0, 1, 2], [0, 4, 8], [1, 2, 3], [1, 4, 2], [2, 3, 1], [3, 4, 1]]<br></span></span><span style="font-size: 18px;"><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">0<br></span><strong style="font-size: 18px;">Explanation:<br></strong><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/711146/Web/Other/blobid2_1745300084.jpg" width="320" height="320"><br><span style="font-size: 18px;">The neighboring cities at a distance of dis for each city are:
City 0 -&gt; [City 1] 
City 1 -&gt; [City 0, City 4] 
City 2 -&gt; [City 3, City 4]
City 3 -&gt; [City 2, City 4]
City 4 -&gt; [City 1, City 2, City 3]
The city 0 has 1 neighboring city at a dis = 2.<br></span></span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&nbsp; ≤&nbsp; n ≤&nbsp; 100<br>1 ≤ m ≤ n*(n-1)/2<br>1 ≤ weight<sub>i </sub>, dis ≤10<sup>4</sup><br></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>Shortest Path</code>&nbsp;<code>BFS</code>&nbsp;<code>Disjoint Set</code>&nbsp;