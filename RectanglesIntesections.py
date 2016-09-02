def solution( K, L, M, N, P, Q, R, S ):
    
    # if intersect at a point or a line, return 0
    area = max( 0, ( min( M, R ) - max( K, P ) ) ) * max( 0, min( N, S ) - max( L, Q ) )

    # won't intersect, return -1
    if M < P:
        return -1

    # area is bigger than the threshold, return -1
    if area > 2147483647:
        return -1

    return area

print( solution( 0, 2, 5, 10, 3, 1, 20, 15 ) ) # 16
print( solution( 0, 0, 1, 1, 1, 1, 2, 2 ) ) # 0
print( solution( 0, 0, 1, 1, 2, 2, 2, 2 ) ) # -1
print( solution( 0, 0, 100000, 100000, 0, 0, 100000000, 100000000 ) ) # -1
