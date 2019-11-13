/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
Example:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int                                 sequence_length = 10;
        int                                 number_of_sequences = s.size() - sequence_length + 1;
        vector<string>                      return_vector;
        int                                 sequence; // 4 values can be stored in 2 bits, 2 * 10 = 20 bits
        unordered_map<int , int >           sequences_repeatation; // sequence, repeatation
        unordered_map<int , int >::iterator iter;
        for (int i = 0; i < number_of_sequences; i++)
        {
            sequence = 0;
            string::iterator str_end = s.begin() + i + sequence_length;
            for (string::iterator str_iter = s.begin() + i; str_iter != str_end; str_iter++)
            {
                switch (*str_iter)
                {
                case 'A':
                    sequence = (sequence << 2);
                    break;
                case 'C':
                    sequence = (sequence << 2) | 1;
                    break;
                case 'G':
                    sequence = (sequence << 2) | 2;
                    break;
                case 'T':
                    sequence = (sequence << 2) | 3;
                    break;
                }
            }
            if ((iter = sequences_repeatation.find(sequence)) == sequences_repeatation.end())
            {
                sequences_repeatation.insert(make_pair(sequence, 1));
            }
            else if (iter->second == 1)
            {
                return_vector.push_back(s.substr(i, sequence_length));
                iter->second++;
            }
        }
        return return_vector;
    }
};