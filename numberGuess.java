import java.util.Random;
import java.util.Scanner;
class numberGuess {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        int playerScore = 0;
        int aiScore = 0;
        int rounds = 5;
        int maxNumber = 100;
        System.out.println("----------------------------------------");
        System.out.println("Welcome to the Number Guessing Battle!");
        System.out.println("----------------------------------------");
        System.out.println("Try to guess the secret number as close as possible.");
        System.out.println("You will compete against the AI in " + rounds + " rounds.");
        System.out.println("The secret number is between 1 and " + maxNumber + ".");
        System.out.println("Whoever gets closer to the secret number scores more points!");
        System.out.println("----------------------------------------");
        for (int round = 1; round <= rounds; round++) {
            System.out.println("Round " + round + " starts!");
            int secretNumber = random.nextInt(maxNumber) + 1;
            System.out.print("Enter your guess (1-" + maxNumber + "): ");
            int playerGuess = sc.nextInt();
            int aiGuess = random.nextInt(maxNumber) + 1;
            System.out.println("AI guesses: " + aiGuess);
            int playerDifference = Math.abs(secretNumber - playerGuess);
            int aiDifference = Math.abs(secretNumber - aiGuess);
            System.out.println("Secret number was: " + secretNumber);
            if (playerDifference < aiDifference) {
                System.out.println("You were closer! You win this round.");
                playerScore += 10;
            } else if (aiDifference < playerDifference) {
                System.out.println("AI was closer! AI wins this round.");
                aiScore += 10;
            } else {
                System.out.println("It's a tie! Both guesses were equally close.");
                playerScore += 5;
                aiScore += 5;
            }
            System.out.println("Current Score -> You: " + playerScore + " | AI: " + aiScore);
            System.out.println("----------------------------------------");
        }
        System.out.println("Game Over!");
        System.out.println("Final Score -> You: " + playerScore + " | AI: " + aiScore);
        if (playerScore > aiScore) {
            System.out.println("Congratulations! You won the battle!");
        } else if (aiScore > playerScore) {
            System.out.println("AI wins the battle! Better luck next time.");
        } else {
            System.out.println("It's a tie! What a close match!");
        }
    }
}
