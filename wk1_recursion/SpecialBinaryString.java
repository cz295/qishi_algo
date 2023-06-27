package wk1_recursion;

import java.util.ArrayList;
import java.util.Collections;

public class SpecialBinaryString {

    public String makeLargestSpecial(String s) {
        if (s.length() == 2) return s;
        int diffBetnOneAndZero = 0, subLength = 0;
        ArrayList<String> res = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') diffBetnOneAndZero++;
            else diffBetnOneAndZero--;
            if (diffBetnOneAndZero == 0) {
                res.add("1" + makeLargestSpecial(s.substring(subLength + 1, i)) + "0");
                subLength = i + 1;
            }

        }
        Collections.sort(res, Collections.reverseOrder());
        return String.join("", res);
    }
}
