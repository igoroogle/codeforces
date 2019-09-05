program zad_B1_5;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, m, n12, i ,j: integer;
  armony : array[0 .. 50000] of string;
  ar1 : array[0 .. 50000] of integer;
  
  st : string;
procedure swap(var a, b : char);
  var
    c : char;
  begin
    c := a;
    a := b;
    b := c;
  end;
 
procedure bsort(l, r : integer; var st : string);
  var
    i, j : integer;
  begin
    for i := l + 1 to r do
      for j := r downto i do
        if(st[j - 1] > st[j]) then
          swap(st[j - 1], st[j]);
  end;
 
function get(var st : string):boolean;
  var
    ch : char;
    i, j, p : integer;
  begin
    for i := length(st) downto 1 do begin
      ch := st[i];
      p := -1;
      for j := i + 1 to length(st) do
        if(st[j] > st[i]) and ((ch = st[i]) or (ch > st[j])) then begin
          p := j;
          ch := st[j];
        end;
 
      if(p <> -1) then begin
        swap(st[i], st[p]);
        bsort(i + 1, length(st), st);
        get := true;
        exit;
      end;
    end;
 
    get := false;
  end;

function get1(st : string):int64;
  var
    res : int64;
    i, j, k : integer;
  begin
    res := 0;

    for i := 1 to n do begin
      k := maxint;
      for j := i to n do begin
        k := min(k, ord(st[j]) - ord('0'));
        inc(res, k);
      end;
    end;

    get1 := res;
  end;

procedure qsort(l, r : integer);
  var
    i, j, m, x, c : integer;
    m1, c1 : string;
  begin
    i := l;
    j := r;
    x := l + random(r - l + 1);

    m1 := armony[x];
    m := ar1[x];

    repeat
      while(ar1[i] > m) or ((ar1[i] = m) and (armony[i] < m1)) do inc(i);
      while(ar1[j] < m) or ((ar1[j] = m) and (armony[j] > m1)) do dec(j);
      if(i <= j) then begin
        c := ar1[i];
        ar1[i] := ar1[j];
        ar1[j] := c;

        c1 := armony[i];
        armony[i] := armony[j];
        armony[j] := c1;

        inc(i);
        dec(j);
      end;
    until(i > j);

    if(i < r) then qsort(i, r);
    if(j > l) then qsort(l, j);
  end;
begin
  readln(n, m);

  st := '';
  for i := 1 to n do
    st := st + chr(ord('0') + i);

  n12 := 1;
  repeat
    armony[n12] := st;
    ar1[n12] := get1(st);
    inc(n12)
  until(not get(st));
  dec(n12);

  qsort(1, n12);
  
  for i := 1 to n do
    write(armony[m, i], ' ');

  readln(n);
end.