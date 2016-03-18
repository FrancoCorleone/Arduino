struct Thread
{
  bool active = false;
  bool finished = false;
  long previous;
  int interval;
  typedef void(*Callback)(Thread*);
  Callback callback;
  void Init(int t, Callback function)
  {
    callback = function;
    interval = t;
    previous = 0;
    finished=false;
  }
  void Restart(long time)
  {
    previous = time;
    finished = false;
  }
  void Stop()
  {
    active = false;
  }
  void Start()
  {
    active = true;
  }
  void Handle(long time)
  {
    if((time-previous)>= interval && active) {
      previous = time;
      callback(this);
    }
  }
};
