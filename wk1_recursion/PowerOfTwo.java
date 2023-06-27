package wk1_recursion;

public class PowerOfTwo {
    public boolean isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n < 2) return true;
        return n % 2 == 0 && isPowerOfTwo(n / 2);
    }
}
