while line = gets
  divisor = line.to_i
  count = 0
  if divisor % 2 != 0
    count = 1999999 / divisor
  end
  if count % 2 == 0
    count = count / 2
  else
    count = count / 2 + 1
  end

  puts count
end