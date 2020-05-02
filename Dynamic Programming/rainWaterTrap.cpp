class Solution
{
public:
    int trap(vector<int> &height)
    {
        int dots = 0;

        if (height.size() > 0) {
            vector<int> dp_left_edge(height);
            vector<int> dp_right_edge(height);

            for (int i = 1; i < height.size(); ++i) {
                dp_left_edge[i] = max(height[i - 1], dp_left_edge[i - 1]);
            }

            for (int i = height.size() - 2; i >= 0; --i) {
                dp_right_edge[i] = max(height[i + 1], dp_right_edge[i + 1]);
            }

            for (int i = height.size() - 2; i > 0; --i) {
                dots += max(min(dp_left_edge[i], dp_right_edge[i]), height[i]) - height[i];
            }
        }

        return dots;
    }
};
/*class Solution {
public:
    int trap(vector<int>& height) {
        int dots = 0;
        if (height.size() > 0)
        {
            int bottom = height[0];
            for (int i = 0; i < height.size(); ++i) // O(n)
            {
                if (height[i] < bottom)
                {
                    bottom = height[i];
                    if (bottom == 0)
                    {
                        break;
                    }
                }
            }
            int first_edge = 0;
            int last_edge = height.size() - 1;
            while (first_edge < last_edge) // O(n)
            {
                for (int i = first_edge; i <= last_edge; ++i) // O(n)
                {
                    if (height[i] > bottom)
                    {
                        first_edge = i;
                        break;
                    }
                }
                for (int i = last_edge; i >= first_edge; --i) // O(n)
                {
                    if (height[i] > bottom)
                    {
                        last_edge = i;
                        break;
                    }
                }
                bottom = min(height[first_edge], height[last_edge]);
                for (int i = first_edge + 1; i < last_edge; ++i) // O(n)
                {
                    if (height[i] < bottom)
                    {
                        dots += (bottom - height[i]);
                        height[i] = bottom;
                    }
                }
            }
        }
        return dots;
    }
};*/