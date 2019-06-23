import java.util.*
import kotlin.collections.ArrayList

fun main() = with(Scanner(System.`in`)){
    val N = nextInt()
    var ret = 0
    val check = BooleanArray(4000001){false}
    for(i in 2..2000) {
        if(!check[i])
        for(j in (i*i)..4000000 step i)
            check[j] = true
    }
    val primes = ArrayList<Int>()
    for(i in 2..4000000)
        if(!check[i])
            primes.add(i)

    fun pick(remain : Int, prevPrime : Int) {
        if(remain == 0) {
            ret++
            return
        }
        if(remain < 0 || prevPrime == primes.size) return
        pick(remain - primes[prevPrime], prevPrime+1)
    }
    for(i in 0 until primes.size)
        if(primes[i] > N)
            break
        else
            pick(N, i)
    println(ret)
}