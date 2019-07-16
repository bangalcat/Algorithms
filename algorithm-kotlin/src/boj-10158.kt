import java.io.BufferedReader
import java.io.FileReader
import java.io.InputStreamReader

// 개미

//fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
fun main() = with(BufferedReader(FileReader("src/input.in"))){
    val (W, H) = readLine().split(' ').map { it.toInt() }
    val (p, q) = readLine().split(' ').map { it.toInt() }
    val t = readLine().toInt()

    val wt = p + t
    val ht = q + t

    val curW =
        when {
            wt / W % 2 == 1 -> W - p % W
            else -> wt % W
        }
    val curH =
        when {
            ht / H % 2 == 1 -> H - q % H
            else -> ht % H
        }
    println("$curW $curH")
}
