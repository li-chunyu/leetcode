class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for idx in range(len(nums)):
            if nums[idx] == -1:
                continue
            else:
                nxt = nums[idx]
                while nxt != -1:
                    tmp = nums[nxt-1]
                    nums[nxt-1] = -1
                    nxt = tmp
        ret = []
        for idx in range(len(nums)):
            if nums[idx] != -1:
                ret.append(idx+1)
        return ret