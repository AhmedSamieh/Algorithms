class Solution {
public:
    string intToRoman(int num) {
        string ret;
        int num4 = num / 1000;
        num %= 1000;
        int num3 = num / 100;
        num %= 100;
        int num2 = num / 10;
        int num1 = num % 10;
        
        for (int i = 0; i < num4 ; i++)
        {
            ret += 'M';
        }
        switch (num3)
        {
            case 9:
                ret += "CM";
                break;
            case 4:
                ret += "CD";
                break;
            case 8:
            case 7:
            case 6:
            case 5:
                ret += "D";
                num3 -= 5;
            default:
                for (int i = 0; i < num3 ; i++)
                {
                    ret += 'C';
                }
                break;
        }
        switch (num2)
        {
            case 9:
                ret += "XC";
                break;
            case 4:
                ret += "XL";
                break;
            case 8:
            case 7:
            case 6:
            case 5:
                ret += "L";
                num2 -= 5;
            default:
                for (int i = 0; i < num2 ; i++)
                {
                    ret += 'X';
                }
                break;
        }
        switch (num1)
        {
            case 9:
                ret += "IX";
                break;
            case 4:
                ret += "IV";
                break;
            case 8:
            case 7:
            case 6:
            case 5:
                ret += "V";
                num1 -= 5;
            default:
                for (int i = 0; i < num1 ; i++)
                {
                    ret += 'I';
                }
                break;
        }
        return ret;
    }
};