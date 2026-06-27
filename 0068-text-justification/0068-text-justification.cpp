class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> currentLine;
        int currentLineChars = 0;

        for (int i = 0; i < words.size(); i++) {
            string currWord = words[i];

            // Check if current word can fit in the line
            if (currentLineChars + currentLine.size() + currWord.size() > maxWidth) {

                int extraSpaces = maxWidth - currentLineChars;
                int gaps = max(1, (int)currentLine.size() - 1);

                int space = extraSpaces / gaps;
                int rem = extraSpaces % gaps;

                // If only one word in the line
                if (currentLine.size() == 1) {
                    while (extraSpaces--) {
                        currentLine[0] += ' ';
                    }
                } else {
                    for (int j = 0; j < currentLine.size() - 1; j++) {
                        for (int k = 0; k < space; k++)
                            currentLine[j] += ' ';

                        if (rem > 0) {
                            currentLine[j] += ' ';
                            rem--;
                        }
                    }
                }

                string line = "";
                for (string &w : currentLine)
                    line += w;

                ans.push_back(line);

                currentLine.clear();
                currentLineChars = 0;
            }

            currentLine.push_back(currWord);
            currentLineChars += currWord.size();
        }

        // Last line (left justified)
        string lastLine = "";

        for (int i = 0; i < currentLine.size(); i++) {
            lastLine += currentLine[i];
            if (i != currentLine.size() - 1)
                lastLine += ' ';
        }

        while (lastLine.size() < maxWidth)
            lastLine += ' ';

        ans.push_back(lastLine);

        return ans;
    }
};