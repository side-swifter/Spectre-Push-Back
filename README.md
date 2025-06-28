# Spectre-Push-Back
our code for the push back season in vex


## Need ts cuz I keep forgeting, use this to push the code to github

```
git add .
git commit -m "akshay is the goat"
git push
```

## Also need this cuz I forget how to replace the my code with the latest github pull for whenever I mess up
```
git fetch origin
git reset --hard origin/main
```


## stuff you gotta know for ez template movement

1. Understanding the Coordinate System
The field’s origin (0, 0) is where the robot starts by default.

X increases to the right, Y increases forward, and angles (theta) increase clockwise.

Set the robot’s starting position with:

cpp
chassis.odom_xyt_set(0_in, 0_in, 0_deg);
2. Move to a Point
To drive to a specific point, use pid_odom_set.

Example: Move forward to (0, 36) inches:

cpp
chassis.pid_odom_set({{0_in, 36_in}, fwd, 110});
chassis.pid_wait();
{0_in, 36_in}: Target position (x, y) in inches.

fwd: Drive forward.

110: Speed limit (0–127).

To drive backward:

cpp
chassis.pid_odom_set({{0, 36}, rev, 110});
chassis.pid_wait();
3. Move to a Point and Face an Angle
Specify the angle you want to end at (in degrees):

cpp
chassis.pid_odom_set({{0_in, 36_in, 45_deg}, fwd, 110});
chassis.pid_wait();
Drives to (0, 36) and ends facing 45 degrees.

4. Multiple Points (Path Following)
Give a list of points for the robot to follow:

cpp
chassis.pid_odom_set({
  {{6_in, 10_in}, fwd, 110},
  {{0_in, 20_in}, fwd, 110},
  {{0_in, 30_in}, fwd, 110}
}, true); // 'true' enables slew for smooth acceleration
chassis.pid_wait();
The robot will pass through each point in order.

5. Turning to a Point
Just turn and face a point without driving:

cpp
chassis.pid_turn_set({24, 24}, fwd, 90);
chassis.pid_wait();
Turns to face the point (24, 24) forward, with a speed limit of 90.

6. Tips
Always use chassis.pid_wait(); after a movement to wait for the robot to finish before starting the next command.

Adjust speed and direction for each movement.

If you want to end at a specific angle, include the angle in the target point.

Summary Table
Action	Example Code
Move to point	chassis.pid_odom_set({{X, Y}, fwd, speed});
Move to point, face angle	chassis.pid_odom_set({{X, Y, angle}, fwd, speed});
Multiple points	chassis.pid_odom_set({{...}, {...}, {...}}, true);
Turn to face point	chassis.pid_turn_set({X, Y}, fwd, speed);
Wait for finish	chassis.pid_wait();
In summary:

Use chassis.pid_odom_set to move to any point (and face an angle if you want).

Use chassis.pid_turn_set to just turn and face a point.

Always use chassis.pid_wait() after each movement.