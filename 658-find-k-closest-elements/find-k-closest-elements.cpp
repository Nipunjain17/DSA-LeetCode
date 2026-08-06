class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
		
		int low = 0, high = n-1;
		int pos = -1;
		
		while(low <= high){
		    int mid = low + (high - low)/2;
		    
		    if(arr[mid] < x){
		        low = mid  +1;
		        pos = mid;
		    }
		    else{
		        high = mid -1;
		    }
		}
		
		vector<int> ans;
		int left = pos, right = pos+1;
		
		while(left >= 0 && right < n && ans.size() < k){
		    int l = abs(x - arr[left]);
		    int r = abs(x - arr[right]);
		    
		    if(l <= r){
		        ans.push_back(arr[left]);
		        left--;
		    }
		    else{
		        ans.push_back(arr[right]);
		        right++;
		    }
		}
		
		while(left >= 0 && ans.size() < k){
		    ans.push_back(arr[left]);
		    left--;
		}
		
		while(right < n && ans.size() < k){
		    ans.push_back(arr[right]);
		    right++;
		}
		sort(ans.begin(), ans.end());
		return ans;
    }
};