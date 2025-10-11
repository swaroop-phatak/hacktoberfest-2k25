import java.util.*;

public class AsteroidCollision {
    public static int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();

        for (int asteroid : asteroids) {
            boolean destroyed = false;

            // Check for collisions only if current asteroid is moving left
            // and top of stack asteroid is moving right
            while (!stack.isEmpty() && asteroid < 0 && stack.peek() > 0) {
                int top = stack.peek();

                if (Math.abs(asteroid) > top) {
                    // The asteroid in stack explodes
                    stack.pop();
                } else if (Math.abs(asteroid) == top) {
                    // Both explode
                    stack.pop();
                    destroyed = true;
                    break;
                } else {
                    // Current asteroid explodes
                    destroyed = true;
                    break;
                }
            }

            // If asteroid survived all collisions, push it to stack
            if (!destroyed) {
                stack.push(asteroid);
            }
        }

        // Convert stack to array
        int[] result = new int[stack.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = stack.pop();
        }
        return result;
    }

    public static void main(String[] args) {
        int[] asteroids = {5, 10, -5};
        System.out.println(Arrays.toString(asteroidCollision(asteroids))); 
        // Output: [5, 10]

        int[] asteroids2 = {8, -8};
        System.out.println(Arrays.toString(asteroidCollision(asteroids2))); 
        // Output: []

        int[] asteroids3 = {10, 2, -5};
        System.out.println(Arrays.toString(asteroidCollision(asteroids3))); 
        // Output: [10]
    }
}
