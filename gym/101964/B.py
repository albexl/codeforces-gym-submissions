line = input().split()

# print(line)

mod = 2 ** 64

a = int(line[0])
b = int(line[1])
c = int(line[2])
n = int(line[3])

if n < 3:
    print(0)
else:
        
    ans = 0;
    
    if n % 2 == 1:
        ans = (n - 1) * (n + 1) // 8
    else:
        ans = (n + 8) * (n - 2) // 8
    
    if a == b and b == c and a == c:
        ans = (ans * n) // 3
    elif a == b or a == c or b == c:
        ans = ans * n
    else:
        ans = ans * 2 * n
    
    ans = ans % mod
    
    print(ans)