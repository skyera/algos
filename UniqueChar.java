// 9/7/2015
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structure.

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

    boolean hasUniqueChars2(String str)
    {
        for (int i = 0; i < str.length() - 1; i++) {
            char ch = str.charAt(i);

            for (int k = i + 1; k < str.length(); k++) {
                char a_ch = str.charAt(k);

                if (ch == a_ch) {
                    return false;
                }
            }
        }    

        return true;
    }

    boolean hasUniqueChar3(String str)
    {
        boolean flags[] = new boolean[256];

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (!flags[ch]) {
                flags[ch] = true;
            } else {
                return false;
            }
        }

        return true;
    }

    public static void test(String str, boolean flag, int which)
    {
        UniqueChar unique = new UniqueChar();

        boolean is_unique = false;
        
        if (which == 1) {
            is_unique = unique.hasUniqueChars(str);
        } else if (which == 2) {
            is_unique = unique.hasUniqueChars2(str);
        } else if (which == 3) {
            is_unique = unique.hasUniqueChar3(str);
        }

        boolean ok = (is_unique == flag);

        if (!ok) {
            System.out.println("Failed for " + str);
        } else {
            System.out.println("pass");
        }
    }
    
    public static void main(String[] args)
    {
        test("abc", true, 1);
        test("aba", false, 1);
        test("", true, 1);
        test("a", true, 1);
        
        test("abc", true, 2);
        test("aba", false, 2);
        test("", true, 2);
        test("a", true, 2);
        
        test("abc", true, 3);
        test("aba", false, 3);
        test("", true, 3);
        test("a", true, 3);
    }
}
