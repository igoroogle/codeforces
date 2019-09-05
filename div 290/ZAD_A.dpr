program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   less:array [1..26,1..26] of boolean;
   kol:array [1..26] of integer;
   a:array [1..110] of string;
   i,j,k,n:integer;
   f:boolean;
   st:string;
procedure complong(s1,s2:string);
var
   m,i:integer;
begin
   if (length(s1)<length(s2)) then m:=length(s1)
   else m:=length(s2);
   for i:=1 to m do
      if (s1[i]<>s2[i]) then
         begin
            if (not (less[ord(s1[i])-96,ord(s2[i])-96])) then inc(kol[ord(s1[i])-96]);
            less[ord(s1[i])-96,ord(s2[i])-96]:=true;
            exit;
         end;
   if (length(s1)<length(s2)) then f:=true;
end;
procedure dfs(k:integer);
var
   p:integer;
begin
   if (kol[k]=0) then
      begin
         st:=st+chr(k+96);
         kol[k]:=-1;
         exit;
      end;
   kol[k]:=-1;
   for p:=1 to 26 do
      begin
         if (less[k,p]) then
            if (kol[p]<>-1) then dfs(p);
      end;
   st:=st+chr(k+96);
end;
begin
   f:=false;
   for i:=1 to 26 do
      for j:=1 to 26 do less[i,j]:=false;
   for i:=1 to 26 do kol[i]:=0;
   readln(n);
   for i:=1 to n do readln(a[i]);
   for i:=2 to n do
      for j:=1 to i-1 do complong(a[i],a[j]);
   for k:=1 to 26 do
      for i:=1 to 26 do
         for j:=1 to 26 do
            if (less[i,k]) and (less[k,j]) then less[i,j]:=true;
   for i:=1 to 26 do
      for j:=1 to 26 do
         if (less[i,j]) and (less[j,i]) then f:=true;
   if (f) then
      begin
         writeln('Impossible');
         readln;
         halt;
      end;
   st:='';
   for i:=1 to 26 do
      if (kol[i]<>-1) then dfs(i);
   writeln(st);
   readln;
end.
