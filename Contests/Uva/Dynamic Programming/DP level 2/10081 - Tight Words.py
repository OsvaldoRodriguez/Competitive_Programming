import sys

def f(i, n, k):
	global dp
	if i == n:
		return 1
	ans = dp[i]
	if ans != -1:
		return ans
	ans = 0
	for j in range(k + 1):
		ans += f(i + 1, n, k)
	dp[i] = ans
	return ans

def g(i, last, n, k):
	global dp2

	if i == n:
		return 1
	ans = dp2[i][last]
	if ans != -1:
		return ans

	ans = 0

	for j in range(k, -1, -1):
		if abs(j - last) <= 1 or i == 0:
			ans += g(i + 1, j, n, k)

	dp2[i][last] = ans
	return ans

for line in sys.stdin:
	k, n = map(int, line.split())
	dp = [-1 for i in range(n + 1)]
	dp2 = [[-1 for i in range(k + 1)] for j in range(n + 1)]
	# print(dp)
	den = f(0, n, k)
	num = g(0, 0, n, k)
	print("{:.5f}".format(num / den * 100.0))
	
