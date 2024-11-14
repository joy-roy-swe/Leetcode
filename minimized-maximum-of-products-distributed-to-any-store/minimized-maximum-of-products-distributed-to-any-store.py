

def minMaximumProducts(n, quantities):
    start, end=1, max(quantities)

    def can_distribute(x):
        stores_needed = 0
        for quantity in quantities:
            stores_needed += (quantity+x-1)//x
            if stores_needed > n:
                return False
        return stores_needed <= n
    
    best_x = end
    while start <= end:
        mid = (start+end)//2
        if can_distribute(mid):
            best_x = mid
            end = mid-1
        else: start = mid+1
    return best_x

# Example Usage
print(minMaximumProducts(6, [11, 6]))  # Output: 3
print(minMaximumProducts(2, [5, 8]))  # Output: 8
print(minMaximumProducts(1, [100000]))  # Output: 100000