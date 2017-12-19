type event = {
  id: int,
  title: string,
  description: string,
  location: string,
  image: string,
  starts_at: string,
  ends_at: string
};

type events = array(event);

let fetchEvents = (callback) =>
  callback([|
    {
      id: 1,
      title: "Event 1",
      description: "Test description",
      location: "Test location",
      image: "Test",
      starts_at: "wow",
      ends_at: "minghi"
    },
    {
      id: 1,
      title: "Event 2",
      description: "Test description",
      location: "Test location",
      image: "Test",
      starts_at: "wow",
      ends_at: "minghi"
    }
  |]);
