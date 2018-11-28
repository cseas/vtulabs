# Create a simulator object
set ns [new Simulator]

# Open NAM trace file
set nf [open pa1.nam w]
$ns namtrace-all $nf

set tf [open pa1.tr w]
$ns trace-all $tf

# Define finish procedure
proc finish {} {
    global ns nf tf
    $ns flush-trace
    # Close NAM trace file
    close $nf
    close $tf
    # Execute NAM on the trace file
    exec nam pa1.nam &
    exit 0
}

# Create four nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

# Create links between the nodes
$ns duplex-link $n0 $n2 20Mb 10ms DropTail
$ns duplex-link $n1 $n2 50Mb 5ms DropTail
$ns duplex-link $n2 $n3 10Mb 1000ms DropTail

# Set queue size of links
$ns queue-limit $n0 $n2 4
$ns queue-limit $n1 $n2 4

# Setup a UDP connection
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

# Setup a CBR over UDP connection
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 5000
$cbr0 set interval_ 0.5
$cbr0 attach-agent $udp0

set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1

set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1

set udp2 [new Agent/UDP]
$ns attach-agent $n2 $udp2

set cbr2 [new Application/Traffic/CBR]
$cbr2  attach-agent $udp2

set null0 [new Agent/Null]
$ns attach-agent $n3 $null0

$ns connect $udp0 $null0
$ns connect $udp1 $null0

# Schedule events for CBR agents
$ns at 0.1 "$cbr0 start"
$ns at 0.2 "$cbr1 start"
$ns at 1.0 "finish"

# Run simulation
$ns run