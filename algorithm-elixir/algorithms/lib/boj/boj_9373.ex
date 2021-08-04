defmodule Boj.Boj9373 do
  @moduledoc """
  ## 입력

  첫째 줄에는 테스트 케이스의 개수 T가 주어진다. (1 ≤ T ≤ 100) 그리고,

  그 다음 줄에 복도의 너비, 정수 w가 주어진다. (1 ≤ w ≤ 100 000) 복도의 양 벽은 직선 x = 0 과 x = w 로 해석한다.
  그 다음 줄에 센서의 개수, 정수 n이 주어진다. (0 ≤ n ≤ 1 000)
  그 다음 각 n개의 줄에 센서의 위치, 반지름을 나타내는 정수 x, y, r 이 주어진다. (0 ≤ x ≤ w, -100 000 ≤ y ≤ 100 000 and 1 ≤ r ≤ 100 000)
  복도의 양 끝은 y = -∞, y = ∞ 이다. 쉽게 말해 센서들의 범위에서 한참 벗어나있다.

  ## 출력

  각 테스트 케이스마다 센서에 감지되지 않고 복도를 지나갈 수 있는 원형 물체의 최대 반지름을 부동소수점 실수로 한 줄에 출력한다.
  물체는 매우 정밀하게 움직일 수 있다고 가정한다. 만약 들키지 않고 지나가는 게 불가능하다면 0을 출력한다. 답은 소수점 아래 6번째 자리까지 정확해야 한다.
  """
  defmodule Pos do
    defstruct [:x, :y, :r]

    def diff(pos1, pos2) do
      (:math.pow(pos1.x - pos2.x, 2) + :math.pow(pos1.y - pos2.y, 2))
      |> :math.sqrt()
      |> Kernel.-(pos1.r + pos2.r)
    end
  end

  defmodule Edge do
    defstruct [:u, :v, :dist]
  end

  @doc """
  sensor들을 전부 그래프로 연결한다. 각 센서들 사이의 틈이 가중치가 된다.
  sensor가 1000개 이하이기 때문에 (양 끝 벽을 포함해서) 최대 1002 * 1002 개의 엣지가 만들어진다.
  100만개가량의 edge들을 정렬시켜 한바퀴 훑으면 끝난다.
  """
  def solve(w, n, sensors_list) do
    UnionFind.start_link(1_500_003)
    sensors_pos = make_sensors_pos(sensors_list)

    make_edges(w, n, sensors_pos)
    |> Enum.reduce_while(0, fn edge, cost ->
      unless UnionFind.same_root?(0, n + 1) do
        unless UnionFind.same_root?(edge.u, edge.v) do
          UnionFind.merge(edge.u, edge.v)
          {:cont, max(cost, edge.dist)}
        else
          {:cont, cost}
        end
      else
        {:halt, cost}
      end
    end)
    |> Kernel./(2)
    |> Float.round(6)
  end

  defp make_sensors_pos(list) do
    list
    |> Enum.map(fn {x, y, r} -> %Pos{x: x, y: y, r: r} end)
  end

  defp make_edges(w, n, sensors_pos) do
    sensors_pos_with_index = sensors_pos |> Enum.with_index(1)

    for {sensor, i} <- sensors_pos_with_index,
        {sensor2, i2} when i != i2 <-
          [{%Pos{x: 0, y: sensor.y, r: 0}, 0}, {%Pos{x: w, y: sensor.y, r: 0}, n + 1}] ++
            sensors_pos_with_index,
        diff = Pos.diff(sensor, sensor2) do
      %Edge{u: i, v: i2, dist: diff}
    end
    |> Enum.sort(&(&1.dist <= &2.dist))
  end
end
