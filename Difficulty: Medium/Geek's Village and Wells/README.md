<h2><a href="https://www.geeksforgeeks.org/problems/geeks-village-and-wells--170647/1?page=3&category=Graph">Geek's Village and Wells</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">Given a matrix <strong>mat[][]</strong> of size n × m representing Geek's village, where:</span></p>
<ul>
<li class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">'H' represents a House.</span></li>
<li class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">'W' represents a Well.</span></li>
<li class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">'.' represents Open Ground.</span></li>
<li class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">'N' represents a Restricted Area that cannot be entered.</span></li>
</ul>
<p class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">Every house needs water from a well. For each house, find the minimum distance required to reach the nearest well and return back to the same house.</span></p>
<p class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">A person can move only in four directions: up, down, left, and right. Movement outside the matrix and entering a restricted cell ('N') is not allowed.</span></p>
<p class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">Return a matrix of the same size as mat[][] where:</span></p>
<ul>
<li class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">For every house ('H'), store the minimum round-trip distance to the nearest reachable well.</span></li>
<li class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">If a house cannot reach any well, store -1.</span></li>
<li class="PDq2pG_selectionAnchorContainer" data-start="41" data-end="103"><span style="font-size: 18.6667px;">For every well ('W'), open ground ('.'), and restricted cell ('N'), store 0.</span></li>
</ul>
<p><strong><span style="font-size: 18px;">Examples :</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 3, m = 3, mat[][] = [[H, H, H], [H, W, H], [H, H, H]]</span>
<span style="font-size: 18px;"><strong>Output: </strong>[[4, 2, 4], [2, 0, 2], [4, 2, 4]]</span>
<span style="font-size: 18px;"><strong>Explanation: </strong></span><span style="font-size: 14pt;">The only well is at the center of the grid. The answer for each house is the <span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">round-trip distance</span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">: 2 * distance to well. </span></span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 4, m = 5, mat[][] = [[H, N, H, N, H], [N, N, ., H, W], [W, H, H, H, .], [H, ., ., N, H]]
</span><span style="font-size: 18px;"><strong>Output: </strong>[[-1, 0, 6, 0, 2], [0, 0, 0, 2, 0], [0, 2, 4, 4, 0], [2, 0, 0, 0, 4]] </span>
<span style="font-size: 18px;"><strong>Explanation: </strong><span style="font-size: 14pt;">There are two wells in the grid. For each house, the minimum distance to reach the nearest well and return back is calculated. The answer is 2 * shortest distance to the well. Cells containing N, ., and W have value 0. The house at (0, 0) cannot reach any well due to blocked paths, so its value is -1. </span><br></span></pre>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>BFS</code>&nbsp;<code>Graph</code>&nbsp;