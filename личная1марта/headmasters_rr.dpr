Var
 x, y, n, m, i, j, ans, local_ans, tmp, res, iter : longint;
 a:array[0..22, 0..22] of boolean;
 p:array[0..22] of longint;
 improved : boolean;
 function get() :longint;
   var i, j, res : longint;
     begin
       res := 0;
       for i := 1 to n do
         for j := i + 1 to n do
           if (a[i][j]) then res := res + abs(p[i] - p[j]);
       get := res;
     end;
  begin
    assign(input,'headmasters.in');
    reset(input);
    assign(output,'headmasters.out');
    rewrite(output);
    read(n, m);
    fillchar(a, sizeof(a), false);
    for i := 1 to m do
      begin
        read(x, y);
        if (x > y) then
          begin
            tmp := x;
            x := y;
            y := tmp;
          end;
        a[x][y] := true;
      end;
    ans := 1000000000;
    for iter := 1 to 10000 do
      begin
        for i := 1 to n do
          begin
            p[i] := i;
            x := random(i) + 1;
            tmp := p[i];
            p[i] := p[x];
            p[x] := tmp;
          end;
        improved := true;
        local_ans := get();
        while (improved) do
          begin
            improved := false;
            for i := 1 to n do
              for j := i + 1 to n do
                begin
                  tmp := p[i];
                  p[i] := p[j];
                  p[j] := tmp;
                  res := get();
                  if (res < local_ans) then
                    begin
                      local_ans := res;
                      improved := true;
                      continue;
                    end;
                  tmp := p[i];
                  p[i] := p[j];
                  p[j] := tmp;
                end;
          end;
        if (local_ans < ans) then ans := local_ans;
      end;
    writeln(ans);
    close(input);
    close(output);
  end.