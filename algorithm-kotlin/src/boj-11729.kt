import java.io.BufferedReader
import java.io.FileReader
import java.io.InputStreamReader
import java.util.*

// 하노이의 탑

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
//fun main() = with(BufferedReader(FileReader("src/input.in"))){
    val N = readLine().toInt()
    val sb = StringBuilder()
    fun hanoi(n : Int, from : Int, by : Int, to : Int) {
        if(n==0) return;
        hanoi(n - 1, from, to, by)
        sb.appendln("$from $to")
        hanoi(n - 1, by, from, to)
    }
    sb.appendln(1.shl(N) - 1)
    hanoi(N, 1, 2, 3)
    print(sb.toString())
}
