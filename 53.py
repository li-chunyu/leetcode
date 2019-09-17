class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        def findMaxSubArraySum(array):
            if len(array) == 1:
                return array[0] 
            if len(array) == 0:
                return float('-inf')
            # compute mid in this way to make sure that left side of the array
            # is alaways the side with less elements.
            mid = (len(array) - 1) // 2
            if mid == 0:
                lMaxSubArraySum = findMaxSubArraySum([])
            else:
                lMaxSubArraySum = findMaxSubArraySum(array[0:mid-1])
            # right side have at least one element.
            rMaxSubArraySum = findMaxSubArraySum(array[mid+1:])

            # comput max sum of continuous sub array that end with array[mid-1]
            # comput max sum of continuous sub array that start with array[mid+1]
            lMaxContinuousArraySum = 0
            rMaxContinuousArraySum = 0
            curMaxContinuousArraySum = 0
            for idx in range(mid-1, -1, -1):
                curMaxContinuousArraySum += array[idx]
                lMaxContinuousArraySum = max(curMaxContinuousArraySum, lMaxContinuousArraySum)

            curMaxContinuousArraySum = 0
            for idx in range(mid+1:len(array)):
                curMaxContinuousArraySum += array[idx]
                rMaxContinuousArraySum = max(curMaxContinuousArraySum, rMaxContinuousArraySum)
            return max(lMaxContinuousArraySum + array[mid] + rMaxContinuousArraySum, 
                        lMaxSubArraySum,
                        rMaxSubArraySum
                      ) 
        
        return findMaxSubArraySum(nums)