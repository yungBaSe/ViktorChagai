for (int A = 0; A < (1 << n); A++)
    for (int B = A; B < (1 << n); B++, B |= A)
        if is[B ∖ A]
            relax (f[B] , f[A] + 1)