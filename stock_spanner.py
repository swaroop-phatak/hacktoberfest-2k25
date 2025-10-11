class StockSpanner:
    """
    This class uses a monotonic stack to efficiently calculate the stock span.
    The stack stores tuples of (price, span).
    """

    def __init__(self):
        # The stack will store pairs: (price, span_for_that_price)
        # It is a "decreasing" monotonic stack, meaning stack elements' prices
        # will be in decreasing order from bottom to top.
        self.stack = []

    def next(self, price: int) -> int:
        """
        Calculates the span of the stock for the current day's price.

        Args:
            price: The price of the stock for the current day.

        Returns:
            The span of the stock for the current day.
        """
        # The span for the current day starts at 1 (for the day itself).
        current_span = 1

        # While the stack is not empty AND the price at the top of the stack
        # is less than or equal to the current price.
        while self.stack and self.stack[-1][0] <= price:
            # We "absorb" the span of the previous, smaller element.
            # Pop the element from the stack.
            prev_price, prev_span = self.stack.pop()
            # Add its span to our current span.
            current_span += prev_span

        # After the loop, the stack is either empty or the top element's
        # price is greater than the current price.
        # Now, push the current price and its calculated span onto the stack.
        self.stack.append((price, current_span))

        # Return the calculated span for the current day.
        return current_span


# Example Usage from the problem description:
# stockSpanner = StockSpanner()
# print(stockSpanner.next(100)) # Output: 1, Stack: [(100, 1)]
# print(stockSpanner.next(80))  # Output: 1, Stack: [(100, 1), (80, 1)]
# print(stockSpanner.next(60))  # Output: 1, Stack: [(100, 1), (80, 1), (60, 1)]
# print(stockSpanner.next(70))  # Output: 2, Stack: [(100, 1), (80, 1), (70, 2)]
# print(stockSpanner.next(60))  # Output: 1, Stack: [(100, 1), (80, 1), (70, 2), (60, 1)]
# print(stockSpanner.next(75))  # Output: 4, Stack: [(100, 1), (80, 1), (75, 4)]
# print(stockSpanner.next(85))  # Output: 6, Stack: [(100, 1), (85, 6)]
