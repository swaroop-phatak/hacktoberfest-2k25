class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        flips = 0
        
        # Iterate through all 32 bits (or until a, b, and c are all 0)
        while a > 0 or b > 0 or c > 0:
            # Get the least significant bit (LSB) for each number
            bit_a = a & 1
            bit_b = b & 1
            bit_c = c & 1
            
            if bit_c == 0:
                # Target bit is 0, so both a's and b's bits must be 0.
                # If bit_a is 1, one flip is needed.
                # If bit_b is 1, one flip is needed.
                flips += bit_a + bit_b
            else: # bit_c == 1
                # Target bit is 1, so at least one of a's or b's bits must be 1.
                # If both bit_a and bit_b are 0, one flip is needed (either a or b).
                if bit_a == 0 and bit_b == 0:
                    flips += 1
            
            # Right shift all numbers to process the next bit
            a >>= 1
            b >>= 1
            c >>= 1
            
        return flips
