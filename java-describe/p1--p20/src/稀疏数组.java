public class 稀疏数组 {
    public static void main(String[] args) {
        int[][] array = new int[5][11];

        array[1][2] = 1;
        array[2][3] = 2;

        int[][] newArray = new int[3][3];
        newArray[0][0] = 5;//row
        newArray[0][1] = 11;//col
        newArray[0][2] = 0;//value

        int m = 1;
        while (m < 3) {
            for (int i = 0; i < array.length; i++) {
                for (int j = 0; j < array[i].length; j++) {
                    if (array[i][j] != 0) {
                        newArray[m][0] = i;
                        newArray[m][1] = j;
                        newArray[m][2] = array[i][j];
                        m++;
                    }
                }
            }

        }


        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[i].length; j++) {
                System.out.print(array[i][j] + "\t");
            }
            System.out.print("\n");
        }

        System.out.print("\n");
        System.out.print("原始数组 --> 稀疏数组");
        System.out.print("\n");

        for (int i = 0; i < newArray.length; i++) {
            for (int j = 0; j < newArray[i].length; j++) {
                System.out.print(newArray[i][j] + "\t");
            }
            System.out.print("\n");
        }

        System.out.print("\n");
        System.out.print("稀疏数组 --> 原始数组");
        System.out.print("\n");

        int[][] toOrigin = new int[newArray[0][0]][newArray[0][1]];
        for (int i = 0; i < toOrigin.length; i++) {
            for (int j = 0; j < toOrigin[i].length; j++) {
                toOrigin[i][j] = newArray[0][2];
            }
        }
        for (int i = 1; i < newArray.length; i++) {
            toOrigin[newArray[i][0]][newArray[i][1]] = newArray[i][2];
        }

        for (int i = 0; i < toOrigin.length; i++) {
            for (int j = 0; j < toOrigin[i].length; j++) {
                System.out.print(toOrigin[i][j] + "\t");
            }
            System.out.print("\n");
        }
    }
}
