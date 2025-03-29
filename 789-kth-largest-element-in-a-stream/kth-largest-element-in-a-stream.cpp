class KthLargest {
public:
    int k;
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
    }

    int add(int val) {
        if (this->nums.size() > 0) {
            int idx = findIndex(val);
            this->nums.insert(this->nums.begin() + idx, val);
            return this->nums[this->nums.size() - this->k];
        }else {
            this->nums.push_back(val);
            return this->nums[0];
        }
    }

private: 
    int findIndex(int val) {
         
        int left = 0, right = this->nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (val < this->nums[mid]) {
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */