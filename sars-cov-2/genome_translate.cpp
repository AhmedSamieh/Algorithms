#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Genome
{
    unordered_map<string, char> codon_aminoacid;
public:
    Genome()
    {
        codon_aminoacid.emplace("UUU", 'F');
        codon_aminoacid.emplace("UUC", 'F');
        codon_aminoacid.emplace("UUA", 'L');
        codon_aminoacid.emplace("UUG", 'L');

        codon_aminoacid.emplace("CUU", 'L');
        codon_aminoacid.emplace("CUC", 'L');
        codon_aminoacid.emplace("CUA", 'L');
        codon_aminoacid.emplace("CUG", 'L');

        codon_aminoacid.emplace("AUU", 'I');
        codon_aminoacid.emplace("AUC", 'I');
        codon_aminoacid.emplace("AUA", 'I');
        codon_aminoacid.emplace("AUG", 'M'); // $ Start

        codon_aminoacid.emplace("GUU", 'V');
        codon_aminoacid.emplace("GUC", 'V');
        codon_aminoacid.emplace("GUA", 'V');
        codon_aminoacid.emplace("GUG", 'V');

        codon_aminoacid.emplace("UCU", 'S');
        codon_aminoacid.emplace("UCC", 'S');
        codon_aminoacid.emplace("UCA", 'S');
        codon_aminoacid.emplace("UCG", 'S');

        codon_aminoacid.emplace("CCU", 'P');
        codon_aminoacid.emplace("CCC", 'P');
        codon_aminoacid.emplace("CCA", 'P');
        codon_aminoacid.emplace("CCG", 'P');

        codon_aminoacid.emplace("ACU", 'T');
        codon_aminoacid.emplace("ACC", 'T');
        codon_aminoacid.emplace("ACA", 'T');
        codon_aminoacid.emplace("ACG", 'T');

        codon_aminoacid.emplace("GCU", 'A');
        codon_aminoacid.emplace("GCC", 'A');
        codon_aminoacid.emplace("GCA", 'A');
        codon_aminoacid.emplace("GCG", 'A');

        codon_aminoacid.emplace("UAU", 'Y');
        codon_aminoacid.emplace("UAC", 'Y');
        codon_aminoacid.emplace("UAA", '*'); // Stop
        codon_aminoacid.emplace("UAG", '*'); // Stop

        codon_aminoacid.emplace("CAU", 'H');
        codon_aminoacid.emplace("CAC", 'H');
        codon_aminoacid.emplace("CAA", 'Q');
        codon_aminoacid.emplace("CAG", 'Q');

        codon_aminoacid.emplace("AAU", 'N');
        codon_aminoacid.emplace("AAC", 'N');
        codon_aminoacid.emplace("AAA", 'K');
        codon_aminoacid.emplace("AAG", 'K');

        codon_aminoacid.emplace("GAU", 'D');
        codon_aminoacid.emplace("GAC", 'D');
        codon_aminoacid.emplace("GAA", 'E');
        codon_aminoacid.emplace("GAG", 'E');

        codon_aminoacid.emplace("UGU", 'C');
        codon_aminoacid.emplace("UGC", 'C');
        codon_aminoacid.emplace("UGA", '*'); // Stop
        codon_aminoacid.emplace("UGG", 'W');

        codon_aminoacid.emplace("CGU", 'R');
        codon_aminoacid.emplace("CGC", 'R');
        codon_aminoacid.emplace("CGA", 'R');
        codon_aminoacid.emplace("CGG", 'R');

        codon_aminoacid.emplace("AGU", 'S');
        codon_aminoacid.emplace("AGC", 'S');
        codon_aminoacid.emplace("AGA", 'R');
        codon_aminoacid.emplace("AGG", 'R');

        codon_aminoacid.emplace("GGU", 'G');
        codon_aminoacid.emplace("GGC", 'G');
        codon_aminoacid.emplace("GGA", 'G');
        codon_aminoacid.emplace("GGG", 'G');
    }
    string to_rna(string &dna) const
    {
        string rna;
        rna.resize(dna.size());
        transform(dna.begin(), dna.end(), rna.begin(), ::toupper);
        replace(rna.begin(), rna.end(), 'T', 'U');
        return rna;
    }
    vector<string> to_codon(string &rna) const
    {
        vector<string> codon;

        if ((rna.size() % 3) == 0) {
            codon.reserve(rna.size() / 3);

            for (size_t i = 0; i < rna.size(); i += 3) {
                codon.emplace_back(rna.substr(i, 3));
            }
        }

        return codon;
    }
    string to_aminoacid(vector<string> &codon) const
    {
        string aminoacid;
        aminoacid.resize(codon.size());
        transform(codon.begin(), codon.end(), aminoacid.begin(), [this](string & i) {
            auto iter = codon_aminoacid.find(i);
            return (iter != codon_aminoacid.end()) ? iter->second : '*';
        });
        return aminoacid;
    }
    vector<string> to_proteins(string &aminoacid)
    {
        vector<string> proteins;
        string protein = "";

        for (auto &c : aminoacid) {
            if (c == '*') {
                if (!protein.empty()) {
                    proteins.emplace_back(protein);
                    protein.erase();
                }
            } else {
                protein.push_back(c);
            }
        }

        return proteins;
    }
};

int main(int, char **argv)
{
    Genome genome;
    ifstream ifs(argv[1]);
    string dna((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    cout << "dna.size: " << dna.size() << endl;
    auto rna = genome.to_rna(dna);
    auto codon = genome.to_codon(rna);
    auto aminoacid = genome.to_aminoacid(codon);
    cout << "aminacid.size: " << aminoacid.size() << endl;
    cout << aminoacid << endl;
    auto proteins = genome.to_proteins(aminoacid);
    cout << "proteins.size: " << proteins.size() << endl;
}

