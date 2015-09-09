// 9/7/2015

public class UniqueChar
{
    boolean hasUniqueChars(String str)
    {
        char count[] = new char[256];
        for (int i = 0; i < 256; i++) {
            count[i] = 0;
        }

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (count[ch] != 0) {
                return false;
            } else {
                count[ch]++;
            }
        }
        return true;
    }

    public static void test(String str, boolean flag)
    {
        UniqueChar unique = new UniqueChar();

        boolean is_unique = unique.hasUniqueChars(str);
        boolean ok = (is_unique == flag);

        if (!ok) {
            System.out.println("Failed for " + str);
        } else {
            System.out.println("pass");
        }
    }

    public static void main(String[] args)
    {
        test("abc", true);
        test("aba", false);
        test("", true);
        test("a", true);

        System.out.println("OK");
    }
}
