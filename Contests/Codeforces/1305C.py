n,m = map(int,input().split())
v = list(map(int,input().split()))
if n > m:
	print(0)
else:
	ans = 1
	for i in range(len(v)):
		for j in range(i + 1,len(v)):
			ans *= abs(v[i] - v[j])
			ans %= m
	print(ans)
