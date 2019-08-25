# alg paper: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
# 想象一群支持不同阵营的人在一起开会，然后打起来了，一个人打倒一个
# 不同阵营的人同时也被另一个不同阵营的人打倒，最终还站着的阵营（可能
# 大于一个人）就是大多数。
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cand = None
        cnt = 0
        for n in nums:
            if cnt == 0:
                cand = n
                cnt = 1
            elif n != cand:
                cnt -= 1
            else:
                cnt += 1
        return cand