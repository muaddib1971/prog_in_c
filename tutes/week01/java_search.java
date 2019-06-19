public class java_search {
    public static int select_item(int haystack[]) {
        return haystack[haystack.length - 1];
    }

    public static void main(String[] args) {
        int[] myhaystack = {1, 3, 5, 7};
        System.out.println(select_item(myhaystack));
    }
}
