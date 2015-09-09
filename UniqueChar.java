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
    
    public static void test2(String str, boolean flag)
    {
        UniqueChar unique = new UniqueChar();

        boolean is_unique = unique.hasUniqueChars2(str);
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
        
        test2("abc", true);
        test2("aba", false);
        test2("", true);
        test2("a", true);
    }
}
