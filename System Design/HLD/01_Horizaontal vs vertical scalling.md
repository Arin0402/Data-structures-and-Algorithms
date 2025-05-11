# Horizontal vs vertical scaling

    - Horizontal                                            Vertical

    - Adding more machines to the system	                Adding more resources (CPU, RAM) to one machine

    - Scale-out                                             Scale-up

    - Multiple servers work in parallel                     Single server becomes more powerful

    - Add more web servers behind a load balancer           Upgrade server from 8GB RAM to 32GB RAM

    - Cost increases with number of servers                 Hardware upgrades can be expensive

    - Resilient                                             Single point of failure

    - Network calls happen so it introduces a bit latency   Inter process communication happens so it is faster

    - Scales well as the users increase                     Hardware limit is there 